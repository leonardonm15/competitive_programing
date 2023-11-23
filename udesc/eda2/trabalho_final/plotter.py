import matplotlib.pyplot as plt
import numpy as np


def plot(time_insert_avl, time_delete_avl):
    n_values = [10, 100, 1000, 10000]
        
    insert_means = np.mean(time_insert_avl, axis=1)

    n_values_fit = np.logspace(1, 5, 100)  # Gera 100 pontos logaritmicamente espaçados entre 10^1 e 10^5
    n_log_n_values = n_values_fit * np.log(n_values_fit)
    n_squared_values = n_values_fit**2

    # Plotagem
    plt.plot(n_values, insert_means, marker='o', label='Insert Times (Data)')
    plt.plot(n_values_fit, n_log_n_values, label='$n \log(n)$')
    plt.plot(n_values_fit, n_squared_values, label='$n^2$')
    plt.xscale('log')  # Escala logarítmica no eixo x
    plt.yscale('log')  # Escala logarítmica no eixo y
    plt.xlabel('Tamanho do N')
    plt.ylabel('Número de Operações')
    plt.title('Tempo Médio de Inserção com $n \log(n)$ e $n^2$')
    plt.legend()
    plt.show()


