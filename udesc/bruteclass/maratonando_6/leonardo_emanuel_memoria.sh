#!/bin/bash

# Nomes completos dos autores:
# Leonardo Nunes Muniz
# Emanuel José Quadras

# Função para coletar informações do sistema
coletar_informacoes() {
    DATA=$(date +%Y%m%d)
    HORA=$(date +%H:%M:%S)
    USUARIO=$(whoami)
    HOST=$(hostname)
    MEM_TOTAL=$(grep MemTotal /proc/meminfo | awk '{print $2}')
    MEM_USADA=$(free | grep Mem | awk '{print $3}')
    SWAP_TOTAL=$(grep SwapTotal /proc/meminfo | awk '{print $2}')
    SWAP_USADA=$(free | grep Swap | awk '{print $3}')
    PROC_USUARIO=$(ps -u $USUARIO | wc -l)
    MEM_PROC_USUARIO=$(ps -u $USUARIO -o rss= | awk '{sum+=$1} END {print sum}')
    PAGE_FAULTS=$(vmstat -s | grep 'page faults' | awk '{print $1}')
    echo "${DATA};${HORA};${USUARIO};${HOST};${MEM_TOTAL};${MEM_USADA};${SWAP_TOTAL};${SWAP_USADA};${PROC_USUARIO};${MEM_PROC_USUARIO};${PAGE_FAULTS}"
}

# Nome do arquivo CSV
DATA_ATUAL=$(date +%Y%m%d)
USUARIO=$(whoami)
ARQUIVO="leonardo_emanuel_${DATA_ATUAL}_memoria_${USUARIO}.csv"

# Cabeçalho do CSV
CABECALHO="Data;Hora;Usuario;Host;Memoria Total (KB);Memoria Usada (KB);Swap Total (KB);Swap Usada (KB);Processos do Usuario;Memoria Processos do Usuario (KB);Page Faults"

# Verifica se o arquivo já existe, caso contrário cria e adiciona o cabeçalho
if [ ! -f "$ARQUIVO" ]; then
    echo "Arquivo criado em: $(date)" > "$ARQUIVO"
    echo "$CABECALHO" >> "$ARQUIVO"
fi

# Adiciona as informações ao arquivo CSV
coletar_informacoes >> "$ARQUIVO"

# Loop para executar a cada 20 segundos durante 5 minutos
END=$((SECONDS+300))
while [ $SECONDS -lt $END ]; do
    sleep 20
    coletar_informacoes >> "$ARQUIVO"
done

