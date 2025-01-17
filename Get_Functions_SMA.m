% ------------------------------------------------------------------------------
%  Please refer to the main paper:
% Main paper (Please refer to the main paper):
% Slime Mould Algorithm: A New Method for Stochastic Optimization
% Shimin Li, Huiling Chen, Mingjing Wang, Ali Asghar Heidari, Seyedali Mirjalili
% Future Generation Computer Systems,2020
% DOI: https://doi.org/10.1016/j.future.2020.03.055
% https://www.sciencedirect.com/science/article/pii/S0167739X19320941
% ------------------------------------------------------------------------------------------------------------
% Website of SMA: http://www.alimirjalili.com/SMA.html
% You can find and run the SMA code online at http://www.alimirjalili.com/SMA.html
% ------------------------------------------------------------------------------


function [lb,ub,dim,fobj] = Get_Functions_SMA(F,DimValue)

switch F
    
    case 'F00'
        fobj = @F00;
        lb=-10;
        ub=10;
        dim=DimValue;
end

end


%F00
function [o, sol]=F00(x,model)
    sol1.x = x(1:2:end);
    sol1.y = x(2:2:end);
    sol=ParseSolution_SMA(sol1,model);
    
    beta=300;
    o=sol.L*(1+beta*sol.Violation);
end