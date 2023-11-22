from random import sample
from ctypes import CDLL
import time

while __name__ == "__main__":
    time_insert_avl = []
    time_delete_avl = []
    avl = r"./avl.so"
    # avl = r"/home/leonardomuniz/contest/competitive_programing/udesc/eda2/trabalho_final/avl.so"
    favl = CDLL(avl)
    termo = 10
    while termo <= 10000:
        insert_time_avl = []
        delete_time_avl = []
        for _ in range(10):
            # insert_time_avl.append(favl.multinsert(termo))
            delete_time_avl.append(favl.multidelete(termo))
        print("tempo atual -> ", delete_time_avl)
        time_insert_avl.append(insert_time_avl)
        time_delete_avl.append(delete_time_avl)
        termo *= 10

    # print("insert operations -> ", time_insert_avl)
    print("delete operations -> ", time_delete_avl)
    # print("Insert Times:", time_insert_avl)
    # print("Delete Times:", time_delete_avl)
    break
