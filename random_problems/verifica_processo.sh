#!/bin/bsh

processo="$1"

resultado=$(pgrep -x "$processo" > /dev/null)
num_pid=$(pgrep -x "$processo")

if $resultado; then
estado=$( ps axo stat,pid | grep "$num_pid" | cut -b 1-3 )
primeira_letra_estado=$(echo $estado | cut -c 1)
echo "$processo ENCONTRADO"
echo "PID: $num_pid"
if [ $primeira_letra_estado = "R" ];then
echo "ESTADO: Running"
fi
if [ $primeira_letra_estado = "S" ];then
echo "ESTADO: Sleeping in an interruptible wait"
fi
if [ $primeira_letra_estado = "D" ];then
echo "ESTADO: Waiting in uninterruptible disk sleep"
fi
if [ $primeira_letra_estado = "Z" ];then
echo "ESTADO: Zombie"
fi
if [ $primeira_letra_estado = "T" ];then
echo "ESTADO: Stopped (on a signal) or (before Linux)"
fi
if [ $primeira_letra_estado = "W" ];then
echo "ESTADO: Paging (only before Linux 2.6.0)"
fi
if [ $primeira_letra_estado = "X" ];then
echo "ESTADO: Dead (from Linux 2.6.0 onward)"
fi
if [ $primeira_letra_estado = "x" ];then
echo "ESTADO: Dead (Linux 2.6.33 to 3.13 only)"
fi
if [ $primeira_letra_estado = "K" ];then
echo "ESTADO: Wakekill (Linux 2.6.33 to 3.13 only)"
fi
if [ $primeira_letra_estado = "P" ];then
echo "ESTADO: Parked (Linux 3.9 to 3.13 only)"
fi
if [ $primeira_letra_estado = "I" ];then
echo "ESTADO: Idle (Linux 4.14 onward)"
fi
else
echo "PROCESSO NÃO ENCONTRADO"
fi
