import asciinet
import numpy as np

# Dados
n_values = [10, 100, 1000, 10000]
insert_times = [[3, 3, 2, 3, 2, 2, 2, 2, 2, 2],
                [65, 61, 61, 62, 60, 62, 64, 56, 60, 72],
                [3593, 4172, 6086, 4203, 4252, 4410, 4120, 4310, 4143, 4156],
                [620103, 664836, 677451, 658803, 673380, 642833, 655939, 666237, 656584, 651717]]

# Calcula as médias
insert_means = np.mean(insert_times, axis=1)

# Criação do gráfico ASCII
chart = asciinet.LineChart()
chart.add_line("Insert Times", n_values, insert_means)
ascii_plot = chart.render()

# Exibição no terminal
print(ascii_plot)
