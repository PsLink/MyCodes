#!/usr/bin/python
# -*- coding: UTF-8 -*-

# Mulitthreading test

import threading
import fileinput
import math
import time


flag = False
End = False
threadLock = threading.Lock()

class myThread (threading.Thread):   
    #继承父类threading.Thread
    def __init__(self, k):
        threading.Thread.__init__(self)
        self.threadID = k

    def run(self):
    	global flag 
    	global End                   
        #把要执行的代码写到run函数里面 线程在创建后会直接运行run函数 
        print "Starting theread %s\n" % str(self.threadID)
        
        start = time.time()

        while True:
        	if (time.time() - start) > self.threadID*1:
        		threadLock.acquire()
        		flag = True
        		print "theread %s change the flag\n" % str(self.threadID)
        		threadLock.release()
        		start = time.time()
        	if End:
        		break
        
        # 获得锁，成功获得锁定后返回True
        #threadLock.acquire()
        # 释放锁
        #threadLock.release()
        print "Exiting theread %s \n" % str(self.threadID)




if __name__ == '__main__':

        print 'thread %s is running...' % threading.current_thread().name
        
        threads = []

        for i in range(2):
	        # 创建新线程
	        threads.append(myThread(i+1))
	        # 开启线程
	        threads[-1].start()

        n = 0
        
        while n<5:
        	
        	if flag:
        		n = n + 1
        		print 'n is %d now...' % n
        		flag = False

        End = True


        # 等待所有线程完成
        for t in threads:
            t.join()