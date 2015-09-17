//
//  main.cpp
//  MC
//
//  Created by sun zewei on 15-7-6.
//  Copyright (c) 2015年 sun zewei. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
#define N 10000
const double h=6.62607e-34;//普朗克常数
const double k=1.38065e-23;//玻尔兹曼常数
const double NA=6.02214e23;//阿伏伽德罗常数
const double pi=3.1415926;//π

int main()
{
    double px,py,pz,nx,ny,nz;
    double en,a,m,Tc=2e-6,dT=2e-8,T,v;
    double nsum,n0;//nsum为总粒子密度，n0为零能级粒子密度
    m=22.989768*1000/NA;//钠原子的原子质量
    for(T=dT;T<=Tc;T+=dT)
    {
        nsum=0;n0=0;//清空总粒子密度与0能级粒子密度
        for(int i=1;i<=N;i++)
        {
            v=10*sqrt(k*T/m);//速度最大值，数量级相等
            px=m*v*double(rand())/RAND_MAX;
            py=m*v*double(rand())/RAND_MAX;
            pz=m*v*double(rand())/RAND_MAX;//三个维度产生随机速度
            nx=px/h;ny=py/h;nz=pz/h;//三个维度的状态数，设V=L*L*L=1
            en=(px*px+py*py+pz*pz)/(2*m);//计算动能
            a=nx*ny*nz/(exp(en/(k*T))-1);//该温度下的粒子密度
            nsum+=a;
            if(en<3.2e-29) n0+=a;//经计算，将3.2*10^(-29)作为零能级
        }
        cout<<T/Tc<<' '<<n0/nsum<<endl;
    }
    return 0;
}

