#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int likelihood(float * V_ob, float * V_teo);
int modelo(float * R, float *Mb, float *Md, float *Mh);


float bb = 0.2497;
float bd = 5.16;
float ad = 0.3105;
float ah = 64.3;

int main(void){
    
    
    
    
    int i,t = 300.0;
    float * R = malloc(t*sizeof(float));
    float * V_ob = malloc(t*sizeof(float));
    float * V_teo = malloc(300*sizeof(float));
    float * m_b = malloc(1000*sizeof(float));
    float * m_d = malloc(1000*sizeof(float));
    float * m_h = malloc(1000*sizeof(float));
    FILE * dat = fopen("RadialVelocities.dat","r");
    FILE * mod = fopen("mod.txt","w"); // Archivo donde guardaré los valores

    likelihood(V_ob, V_teo);
    modelo(R, Mb, Md, Mh);
    

    for (i=0; i<t; i++){
        fscanf(dat, "%f %f\n", &R[i], &V_ob[i]);
        printf("%f %f\n",R[i],V_ob[i]);
    }
    fclose(dat);
    
    
    
    return 0;
}


int likelihood(float * V_ob, float * V_teo){
    
    int j;
    
    float sumaV = 0.0;
    for (j=0; j<300.0; j++){
        
        float * sum = malloc(300*sizeof(float));
        sum[j] = V_ob[j] + V_teo[j];
        sumaV = sum[j] + sumaV;
    }
    
    float res = 0.5*pow((sumaV),2);
    
    return res;
}

int modelo(float *m_b, float *m_d, float *m_h, float * R){
    
    
    float A = pow(R,2) + pow(bb,2);
    float B = pow(R,2) + pow(bd + ad,2);
    float C = pow(R,2) + pow(ah,2);
    V_teo = (sqrt(m_b)*R)/pow(A,3/4) + (sqrt(m_d)*R)/pow(B,3/4) + (sqrt(m_h)*R)/pow(C,0.25);
    
    return V_teo;
}

