function runProgram(showPlot, NrCard)
    %% Initialization
    %showPlot = 0;    % Plot frequency (0: never, 1: every iteration, 2: every second iteration, etc.)
    %NrCard = 7;     % Number of card (Card 7 and 11 are interesting for us)
    Function_name='F00';    % F00: path finding for mobile robots
    StpIt = 100;     % Maximum iterations without improvement before stopping
    StpEps = 1e-2;   % Convergence threshold
    
    %% Setup
    % Initialize map with start and end points
    [model, lb, ub, NumberofPoints, T, N] = CreateModelSMA(NrCard); 
    dimSize = NumberofPoints*2;   % Each point has x and y coordinates
    
    % Load benchmark function parameters
    [~, ~,dim,fobj]=Get_Functions_SMA(Function_name,dimSize);
    
    %% Run SMA Algorithm
    tic
    [Destination_fitness,bestPositions,Convergence_curve,X] = SMA(N,T,lb,ub,dim,fobj, model, Function_name, showPlot, StpIt, StpEps);
    toc
    
    %% Visualization
    % Plot convergence history
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
    
    % Plot final path
    figure
    if strcmp(Function_name, 'F00')
        [AllFitness, sol] = fobj(bestPositions, model);
        PlotSolution_SMA(sol, model);
        title(['Best Result of SMA with path length of: ' sprintf('%.2f',AllFitness)])
    end
    
    %display(['The best location of SMA is: ', sprintf('%.2f',bestPositions)]);
    display(['The best fitness of SMA is: ', sprintf('%.2f',Destination_fitness)]);
end

