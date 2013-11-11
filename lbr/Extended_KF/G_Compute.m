function [G]=G_Compute(SV_Pos,Rcv_Pos);
[m,n]=size(SV_Pos);
for i=1:m
    d(i)=norm(SV_Pos(i,:)-Rcv_Pos);
    dif=SV_Pos(i,:)-Rcv_Pos;
    unit=dif./d(i);
    for j=1:n
        Unit_Mtrix(i,j)=unit(j);
    end
end
G=[-Unit_Mtrix ones(m,1)];
