import os
import subprocess
import random


def pot(x):
    ans=[0 for i in range(100)]
    x1=str(x)
    for i in range(len(x1)):
        for j in range(len(x1)):
            ans[i+j]=(ans[i+j]+int(x1[i])*int(x1[j]))%10
    res=""
    for i in range(100):
        res+=str(ans[i])
    res=str(int(res[::-1]))[::-1]
    return res
