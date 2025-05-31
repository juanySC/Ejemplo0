import matplotlib.pyplot as plt
from matplotlib_venn import venn2, venn3
import re  # Necesario para manejar el complemento con seguridad

# función para ingresar elementos de un conjunto desde el usuario
def ingresar_elementos_conjunto(conjunto_numero):
    entrada = input(f"Ingrese los elementos del conjunto {conjunto_numero}, separados por comas o espacios (deje vacio si es conjunto vacio): ")
    elementos = set(entrada.replace(",", " ").split())
    if not elementos:
        return {"__vacio__"}
    elif len(elementos) > 15:
        print("No puede ingresar más de 15 elementos.")
        return ingresar_elementos_conjunto(conjunto_numero)
    return elementos

# función para dibujar diagramas de Venn para 2 o 3 conjuntos
def dibujar_diagrama_venn(conjuntos, etiquetas):
    num = len(conjuntos)
    conjuntos = [c if c != {"__vacio__"} else set() for c in conjuntos]
    if num == 2:
        A, B = conjuntos
        venn = venn2([A, B], set_labels=etiquetas)
        regiones = {'10': A - B, '01': B - A, '11': A & B}
        for k, v in regiones.items():
            if venn.get_label_by_id(k):
                venn.get_label_by_id(k).set_text('\n'.join(sorted(v)))
        plt.title("Diagrama de Venn (2 conjuntos)")
        plt.show()
    elif num == 3:
        A, B, C = conjuntos
        venn = venn3([A, B, C], set_labels=etiquetas)
        regiones = {
            '100': A - B - C,
            '010': B - A - C,
            '001': C - A - B,
            '110': A & B - C,
            '101': A & C - B,
            '011': B & C - A,
            '111': A & B & C
        }
        for k, v in regiones.items():
            if venn.get_label_by_id(k):
                venn.get_label_by_id(k).set_text('\n'.join(sorted(v)))
        plt.title("Diagrama de Venn (3 conjuntos)")
        plt.show()

# función para mostrar un conjunto en consola de forma legible
def mostrar_resultado(nombre, conjunto):
    if conjunto == {"__vacio__"} or not conjunto:
        print(f"{nombre} = {{}}")
    else:
        print(f"{nombre} = {{{', '.join(sorted(conjunto))}}}")

# evalúa una expresión de conjuntos con operadores como |, &, -, ^, ~
def evaluar_expresion(expr, conjuntos):
    try:
        # Primero, manejar el complemento (~A → (conjuntos['U'] - conjuntos['A']))
        expr = re.sub(r'~\s*([A-J])', lambda m: f"(conjuntos['U'] - conjuntos['{m.group(1)}'])", expr)

        # Luego, reemplazar A, B, C, ... por conjuntos['A'], etc. sin reemplazar dentro de otros textos ya evaluados
        for nombre in conjuntos:
            expr = re.sub(rf"\b{nombre}\b(?!'])", f"conjuntos['{nombre}']", expr)

        resultado = eval(expr)
        return resultado
    except Exception as e:
        print(f"Error al evaluar la expresion: {e}")
        return None

# función principal
def main():
    conjuntos = {}
    nombres = ['A','B','C','D','E','F','G','H','I','J']

    num = int(input("Cuántos conjuntos deseas ingresar? (máximo 10): "))
    if not (1 <= num <= 10):
        print("Número fuera de rango.")
        return

    for i in range(num):
        elementos = ingresar_elementos_conjunto(i + 1)
        conjuntos[nombres[i]] = elementos

    print("\nConjuntos ingresados:")
    for k in conjuntos:
        mostrar_resultado(k, conjuntos[k])

    if num in (2, 3):
        etiquetas = nombres[:num]
        conjuntos_a_usar = [conjuntos[n] for n in etiquetas]
        dibujar_diagrama_venn(conjuntos_a_usar, etiquetas)

    # Calcular conjunto universal
    conjunto_universal = set()
    for s in conjuntos.values():
        if s != {"__vacio__"}:
            conjunto_universal |= s
    conjuntos["U"] = conjunto_universal

    # Guía para el usuario
    print("\n=== OPERACIONES CON CONJUNTOS ===")
    print("Para unión use: A | B")
    print("Para intersección use: A & B")
    print("Para diferencia use: A - B")
    print("Para diferencia simétrica use: A ^ B")
    print("Para complemento use: ~A (usa U como conjunto universal)")

    continuar = True
    while continuar:
        expresion = input("\nIngrese la expresión de conjuntos: ").strip()
        resultado = evaluar_expresion(expresion, conjuntos)
        if resultado is not None:
            mostrar_resultado("Resultado", resultado)
            usados = [n for n in nombres if n in expresion]
            if len(usados) in (2, 3):
                etiquetas = usados
                conjuntos_a_usar = [conjuntos[n] for n in etiquetas]
                dibujar_diagrama_venn(conjuntos_a_usar, etiquetas)
        continuar = input("¿Deseas ingresar otra expresión? (s/n): ").lower() == 's'

# ejecutar programa
main()
