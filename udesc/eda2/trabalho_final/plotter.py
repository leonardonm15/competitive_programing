import matplotlib.pyplot as plt
import numpy as np

# Dados
n_values = [10, 100, 1000, 10000, 100000]
insert_times = [[424, 848, 1272, 1696, 2120, 2544, 2968, 3392, 3816, 4240],
                [29688, 55136, 80584, 106032, 131480, 156928, 182376, 207824, 233272, 258720],
                [2421251, 4583782, 6746313, 8908844, 11071375, 13233906, 15396437, 17558968, 19721499, 21884030],
                [230481225, 433652397, 638534824, 843417251, 1047212509, 1254252228, 1464334807, 1668770179, 1870739735, 2073177420]]
insert_times = [48, 1076, 17376, 242970, 3102794]

# Calcula as médias
insert_means = insert_times

# Calcula os valores das funções n log(n) e n^2
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

