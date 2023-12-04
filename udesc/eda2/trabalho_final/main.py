from random import sample
from ctypes import CDLL
from plotter import *
import time

while __name__ == "__main__":
    # variáveis que vão guardar os número de comparações
    insert_time_avl = []
    delete_time_avl = []

    insert_time_rb= []
    delete_time_rb = []

    insert_time_bt1 = []
    delete_time_bt1 = []

    insert_time_bt5 = []
    delete_time_bt5 = []

    insert_time_bt10 = []
    delete_time_bt10 = []
    
    # paths
    avl = r"./avl.so"
    rb = r"./rb.so"
    bt = r"./bt.so"

    # declaração dos wrappers
    favl = CDLL(avl)
    frb = CDLL(rb)
    fbt = CDLL(bt)
    
    for termo in [1, 10, 100, 1000, 10000]: 
        print(f"-------- TERMO {termo} --------")
        insert_time_avl.append(favl.multinsert(termo))
        delete_time_avl.append(favl.multidelete(termo))
        print(f"----- avl feito -----");

        insert_time_rb.append(frb.multinsert(termo))
        delete_time_rb.append(frb.multidelete(termo))
        print(f"----- rb feito -----")

        insert_time_bt1.append(fbt.multinsert(termo, 1))
        delete_time_bt1.append(fbt.multidelete(termo, 1))
        print(f"----- bt1 feito -----")

        insert_time_bt5.append(fbt.multinsert(termo, 5))
        delete_time_bt5.append(fbt.multidelete(termo, 5))
        print(f"----- bt5 feito -----")

        insert_time_bt10.append(fbt.multinsert(termo, 10))
        delete_time_bt10.append(fbt.multidelete(termo, 10))
        print(f"----- bt10 feito -----")
    

    # print("avl insert.len -> ", insert_time_avl)

    print("avl insert.len -> ", len(insert_time_avl))
    print("avl delete.len -> ", len(delete_time_avl))
    print("rb insert.len -> ", len(insert_time_rb))
    print("rb delete.len -> ", len(delete_time_rb))
    print("insert_time_bt1 -> ", len(insert_time_bt1))
    print("delete_time_bt1 -> ", len(delete_time_bt1))
    print("insert_time_bt5 -> ", len(insert_time_bt5))
    print("delete_time_bt5 -> ", len(delete_time_bt5))
    print("insert_time_bt10 -> ", len(insert_time_bt10))
    print("delete_time_bt10 -> ", len(delete_time_bt10))

    plot(len(insert_time_avl), insert_time_avl, insert_time_rb, insert_time_bt1, insert_time_bt5, insert_time_bt10, 
         delete_time_avl, delete_time_rb, delete_time_bt1, delete_time_bt5, delete_time_bt10)
    break;
