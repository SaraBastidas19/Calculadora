#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Stack {
    float items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
    for (int i = 0; i < MAX_SIZE; i++) {
        stack->items[i] = 0.0;
    }
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, float value) {
    if (!isFull(stack)) {
        stack->top++;

        for (int i = stack->top; i > 0; i--) {
            stack->items[i] = stack->items[i - 1];
        }

        stack->items[0] = value;
        printf("Valor %.2f agregado a la pila.\n", value);
    } else {
        printf("La pila está llena, no se puede agregar.\n");
    }
}

float pop(struct Stack *stack) {
    if (stack->top >= 0) {
        float value = stack->items[0];
        
        for (int i = 0; i < stack->top; i++) {
            stack->items[i] = stack->items[i + 1];
        }
        
        stack->items[stack->top] = 0.0;
        stack->top--;
        return value;
    }
    printf("La pila está vacía.\n");
    return -1.0;
}

int main() {
    int opcion = 0;
    int caso2=0;

    struct Stack pila;
    initialize(&pila);

    printf("Calculadora\n");

    while (opcion != 5) {
        printf("Ingrese una opción:\n");
        printf("1. Agregar un número\n");
        printf("2. Realizar Operación\n");
        printf("3. Limpiar Ultimo\n");
        printf("4. Limpiar todo\n");
        printf("5. Salir\n");

        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                float valor;

                printf("Ingrese el valor a agregar: ");
                scanf("%f", &valor);

                push(&pila, valor);

                break;

            case 2:
                printf("Ingrese una opción:\n");
                printf("1. Suma\n");
                printf("2. Resta (Por implementar)\n");
                printf("3. Multiplicación (Por implementar)\n");
                printf("4. División (Por implementar)\n");
                printf("5. Seno (Por implementar)\n");
                printf("6. Coseno (Por implementar)\n");
                printf("7. Tangente (Por implementar)\n");
                scanf("%d", &caso2);
                switch (caso2) {
                    case 1:
                        if (pila.top >= 1) {
                        float segundoValor = pop(&pila);
                        float primerValor = pop(&pila);
                        float suma = primerValor + segundoValor;
                        push(&pila, suma);
                    } else {
                        printf("No hay suficientes valores para sumar.\n");
                    }
                    break;
                    
                    case 2:
                        if (pila.top >= 1) {
                        float segundoValor = pop(&pila);
                        float primerValor = pop(&pila);
                        float resta = segundoValor - primerValor;
                        push(&pila, resta);
                        } else {
                        printf("No hay suficientes valores para restar.\n");
                        }
                    
                        break;
                    case 3:
                            if (pila.top >= 1) {
                        float segundoValor = pop(&pila);
                        float primerValor = pop(&pila);
                        float mult = segundoValor * primerValor;
                        push(&pila, mult);
                        } else {
                        printf("No hay suficientes valores para multiplicar.\n");
                        }
                        break;
                    case 4:
                       if (pila.top >= 1) {
                        float segundoValor = pop(&pila);
                        float primerValor = pop(&pila);
                        if(primerValor == 0){
                            printf("No se puede dividir por cero.\n");
                        }
                        else{
                            float div = segundoValor / primerValor;
                            push(&pila, div);
                        }
                        } else {
                        printf("No hay suficientes valores para dividir.\n");
                        }
                        break;

                    case 5:
                       if (pila.top >= 1) {
                        float segundoValor = pop(&pila);
                        float primerValor = pop(&pila);
                        if(primerValor == 0){
                            printf("No se puede dividir por cero.\n");
                        }
                        else{
                            float div = segundoValor / primerValor;
                            push(&pila, div);
                        }
                        } else {
                        printf("No hay suficientes valores para dividir.\n");
                        }
                        break;
                }
                
            break;

             case 3:
                float primerValor = pop(&pila);
                break;

            case 4:
                initialize(&pila);
                printf("Pila limpiada.\n");
                break;


            case 5:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción no válida.\n");
        }

        // Imprimir la pila con ceros
        printf("Pila:\n");
        for (int i = MAX_SIZE - 1; i >= 0; i--) {
            printf("%.2f\n", pila.items[i]);
        }
    }

    return 0;
}