from random import sample
from ctypes import CDLL
# from plotter import *
import time

while __name__ == "__main__":
    # variáveis que vão guardar os número de comparações
    comp_insert_avl = []
    comp_delete_avl = []

    comp_insert_rb = []
    comp_delete_rb = []
    
    # paths
    avl = r"./avl.so"
    rb = r"./rb.so"

    # declaração dos wrappers
    favl = CDLL(avl)
    frb = CDLL(rb);

    # k = 10
    # while k > 0:
    #     print("-------------------")
    #     print(frb.multinsert(10000))
    #     print(frb.multidelete(10000))
    #     k -= 1

    termo = 10
    while termo <= 10000:
        insert_time_avl = []
        delete_time_avl = []

        insert_time_rb = []
        delete_time_rb = []

        for _ in range(10):
            print(f"operações de range {termo}")
            insert_time_avl.append(favl.multinsert(termo))
            delete_time_avl.append(favl.multidelete(termo))
            print("avl feito");

            insert_time_rb.append(frb.multinsert(termo))
            delete_time_rb.append(frb.multidelete(termo))
            print("rb feito")

        comp_insert_avl.append(insert_time_avl)
        comp_delete_avl.append(delete_time_avl)

        comp_insert_rb.append(insert_time_rb)
        comp_delete_rb.append(delete_time_rb)
        
        termo *= 10
    
    # plot(time_insert_avl, time_delete_avl)

    print("insert operations -> ", time_insert_avl)
    print("delete operations -> ", time_delete_avl)
    print("-------------------------------------")
    print("insert operations -> ", time_insert_rb)
    print("delete operations -> ", time_delete_rb)
    break;
