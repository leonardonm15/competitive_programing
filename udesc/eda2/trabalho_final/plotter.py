import matplotlib.pyplot as plt
import numpy as np

def plot(n_values, insert_time_avl, insert_time_rb, insert_time_bt1, insert_time_bt5,
         insert_time_bt10, delete_time_avl, delete_time_rb, delete_time_bt1,
         delete_time_bt5, delete_time_bt10):
    
    # Primeiro gráfico: Comparação entre valores de inserção
    plt.figure(figsize=(12, 6))
    plt.subplot(1, 2, 1)
    plt.plot(n_values, insert_time_avl, label='AVL Tree')
    plt.plot(n_values, insert_time_rb, label='Red-Black Tree')
    plt.plot(n_values, insert_time_bt1, label='B-Tree (degree=1)')
    plt.plot(n_values, insert_time_bt5, label='B-Tree (degree=5)')
    plt.plot(n_values, insert_time_bt10, label='B-Tree (degree=10)')
    plt.plot(n_values, n_values * np.log(n_values), label='$n \log(n)$', linestyle='dashed', color='black')
    plt.xscale('log')
    plt.yscale('log')
    plt.xlabel('Tamanho do N')
    plt.ylabel('Tempo de Inserção')
    plt.title('Comparação de Valores de Inserção')
    plt.tight_layout()
    plt.legend()

    # Segundo gráfico: Comparação entre valores de deleção
    plt.subplot(1, 2, 2)
    plt.plot(n_values, delete_time_avl, label='AVL Tree')
    plt.plot(n_values, delete_time_rb, label='Red-Black Tree')
    plt.plot(n_values, delete_time_bt1, label='B-Tree (degree=1)')
    plt.plot(n_values, delete_time_bt5, label='B-Tree (degree=5)')
    plt.plot(n_values, delete_time_bt10, label='B-Tree (degree=10)')
    plt.plot(n_values, n_values * np.log(n_values), label='$n \log(n)$', linestyle='dashed', color='black')
    plt.xscale('log')
    plt.yscale('log')
    plt.xlabel('Tamanho do N')
    plt.ylabel('Tempo de Deleção')
    plt.title('Comparação de Valores de Deleção')
    plt.tight_layout()
    plt.legend()
    plt.savefig('results/resultado.png')



