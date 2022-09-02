import time
import timeit
from datetime import datetime
import pytz
tz_India = pytz.timezone('Asia/Kolkata')
now = datetime.now(tz_India)
current_time = now.strftime("%H:%M:%S")
print("System Time =", current_time)
t1=time.time()

n=1024
A=[[0 for i in range(n)] for j in range(n)]
B=[[0 for i in range(n)] for j in range(n)]
C=[[0 for i in range(n)] for j in range(n)]
for i in range(n):
    for j in range(n):
        A[i][j]=1.5
        B[i][j]=1.5
        C[i][j]=0.0
m_time1=time.time()
for i in range(n):
    for j in range(n):
        for k in range(n):
            C[i][j]+=A[i][k]*B[k][i]
m_time2=time.time()
t2=time.time()
print('Total Program Execution time:',t2-t1)
print('Time for Matrix multiplication block:',m_time2-m_time1)
temp1=t2-t1
temp2=m_time2-m_time1
print('Percentage of Matrix multiplication w.r.t Total program exe time:',(temp2/temp1)*100)
