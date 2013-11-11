function [Delta_Rho]=Delta_Rho_Compute(Rhoc,SV_Pos,Rcv_Pos,b);
[m,n]=size(SV_Pos);
for i=1:m
    Rho0(i)=norm(SV_Pos(i,:)-Rcv_Pos)+b;
    Delta_Rho(i,1)=Rhoc(i)-Rho0(i);
end