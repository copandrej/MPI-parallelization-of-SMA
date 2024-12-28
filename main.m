% Author and Programmer:
% Christian Karg 
%
% For the code structure of the oprtimization problem of path finding, to 
% which the algorithms are applied, is inspired by Yarpiz:
%
% https://yarpiz.com/50/ypea102-particle-swarm-optimization
%
%---------------------------------------------------------------------------------------------------------------------------


clear all 
close all
clc

%% Intitialisierung
showPlot = 0; % Wie oft soll die aktuelle Lösung geplottet werden (0 -> nie
% , 1 -> jedes Mail, 2 -> jedes zweite Mal,..., 5 -> jedes fünfte Mal, ...)
NrCard = 11;

Function_name='F00'; % Name of the test function, range from F10-F13 % F00 for the problem of pathfinding for mobile robots

StpIt = 100; % nach, wie vielen Runden bei keiner Änderung gestoppt werden soll
StpEps = 1e-2; % Schranke für keine Änderung

%% Code
% Festlegen der Karte, inkl. Start und Endpunkt
[model, lb, ub, NumberofPoints, T, N] = CreateModelSMA(NrCard); 

dimSize = NumberofPoints*2;   %dimension size

% Load details of the selected benchmark function
[~, ~,dim,fobj]=Get_Functions_SMA(Function_name,dimSize);

% SMA Algorithmus
tic
[Destination_fitness,bestPositions,Convergence_curve,X] = SMA(N,T,lb,ub,dim,fobj, model, Function_name, showPlot, StpIt, StpEps);
toc
%% Plots
% Convergernce Curve
figure,
hold on
semilogy(Convergence_curve,'Color','b','LineWidth',4);
title('Convergence curve')
xlabel('Iteration');
ylabel('Best fitness obtained so far');
axis tight
grid off
box on
legend('SMA')

% Final Result
figure
if strcmp(Function_name, 'F00')
    [AllFitness, sol] = fobj(bestPositions, model);
    PlotSolution_SMA(sol, model);
    title(['Best Result of SMA with path length of: ' num2str(AllFitness)])
else
    points = [start bestPositions End];
    points2 = zeros(length(points)/2, 2);
    k=1;
    for i=1:2:length(points)
        points2(k,:) = [points(i) points(i+1)]';
        k=k+1;
    end
    plot(points2(:,1),points2(:,2),'--o')
end


display(['The best location of SMA is: ', num2str(bestPositions)]);
display(['The best fitness of SMA is: ', num2str(Destination_fitness)]);