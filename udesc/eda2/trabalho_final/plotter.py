import matplotlib.pyplot as plt
import numpy as np

def plot(n_values, insert_time_avl, insert_time_rb, insert_time_bt1, insert_time_bt5,
         insert_time_bt10, delete_time_avl, delete_time_rb, delete_time_bt1,
         delete_time_bt5, delete_time_bt10):
    

    n_values = [max(cara, 1) for cara in range(1, n_values + 1)]
    n_log_n_values = n_values * np.log(n_values)

    # Normaliza os tempos de inserção
    insert_time_avl_norm = insert_time_avl / n_log_n_values
    insert_time_rb_norm = insert_time_rb / n_log_n_values
    insert_time_bt1_norm = insert_time_bt1 / n_log_n_values
    insert_time_bt5_norm = insert_time_bt5 / n_log_n_values
    insert_time_bt10_norm = insert_time_bt10 / n_log_n_values

    # Normaliza os tempos de deleção
    delete_time_avl_norm = delete_time_avl / n_log_n_values
    delete_time_rb_norm = delete_time_rb / n_log_n_values
    delete_time_bt1_norm = delete_time_bt1 / n_log_n_values
    delete_time_bt5_norm = delete_time_bt5 / n_log_n_values
    delete_time_bt10_norm = delete_time_bt10 / n_log_n_values

    # Primeiro gráfico: Comparação entre valores de inserção
    plt.figure(figsize=(12, 6))
    plt.subplot(1, 2, 1)
    plt.plot(n_values, insert_time_avl_norm, marker='o', label='AVL Tree')
    plt.plot(n_values, insert_time_rb_norm, marker='o', label='Red-Black Tree')
    plt.plot(n_values, insert_time_bt1_norm, marker='o', label='B-Tree (degree=1)')
    plt.plot(n_values, insert_time_bt5_norm, marker='o', label='B-Tree (degree=5)')
    plt.plot(n_values, insert_time_bt10_norm, marker='o', label='B-Tree (degree=10)')
    plt.plot(n_values, np.ones_like(n_values), label='$n \log(n)$', linestyle='dashed', color='black')
    plt.xscale('log')
    plt.yscale('log')
    plt.xlabel('Tamanho do N')
    plt.ylabel('Tempo de Inserção Normalizado')
    plt.title('Comparação de Valores de Inserção Normalizados')
    plt.tight_layout()
    plt.legend()

    # Segundo gráfico: Comparação entre valores de deleção
    plt.subplot(1, 2, 2)
    plt.plot(n_values, delete_time_avl_norm, marker='o', label='AVL Tree')
    plt.plot(n_values, delete_time_rb_norm, marker='o', label='Red-Black Tree')
    plt.plot(n_values, delete_time_bt1_norm, marker='o', label='B-Tree (degree=1)')
    plt.plot(n_values, delete_time_bt5_norm, marker='o', label='B-Tree (degree=5)')
    plt.plot(n_values, delete_time_bt10_norm, marker='o', label='B-Tree (degree=10)')
    plt.plot(n_values, np.ones_like(n_values), label='$n \log(n)$', linestyle='dashed', color='black')
    plt.xscale('log')
    plt.yscale('log')
    plt.xlabel('Tamanho do N')
    plt.ylabel('Tempo de Deleção Normalizado')
    plt.title('Comparação de Valores de Deleção Normalizados')
    plt.tight_layout()
    plt.legend()
    plt.savefig('results/resultado.png')

    

