n=int(raw_input('Ingresar el numero de variables '))-1
t=[0]*(n+1)
x=[0]*(n+1)
for i in range(n+1):
    t[i]=float(raw_input('Ingrese el elemento t[%d] '%(i)))
    x[i]=float(raw_input('Ingrese el elemento x[%d] '%(i)))
# algoritmo 
for k in range (0,n,1):
    for i in range(n,k,-1):
        x[i]=(x[i]-x[i-1])/(t[i]-t[i-k-1])
for k in range (n-1,-1,-1):
   for i in range(k,n,1):
        x[i]=x[i]-t[k]*x[i+1]
