%
% Copyright (c) 2015, Yarpiz (www.yarpiz.com)
% All rights reserved. Please read the "license.txt" for license terms.
%
% Project Code: YPAP115
% Project Title: Path Planning using PSO in MATLAB
% Publisher: Yarpiz (www.yarpiz.com)
% 
% Developer: S. Mostapha Kalami Heris (Member of Yarpiz Team)
% 
% Contact Info: sm.kalami@gmail.com, info@yarpiz.com
%

function [model, lb, ub, NumberofPoints, T, N] =CreateModelSMA(i)

    % Source
    xobs = [];
    yobs = [];
    
    % Target (Destination)

    
    switch i
        case 7
            % Check lengths of generated arrays
            horizontal_bottom = 3:1.5:15;  % Increased spacing
            horizontal_top = 3:1.5:15;     
            horizontal_middle = 3:1.5:8;   
            vertical_left = 3*ones(1,6);   % Reduced number of obstacles due to larger size
            vertical_middle = 8*ones(1,6); 
            vertical_right = 15*ones(1,6); 

            xs = 2;
            ys = 2;

            xobs = [horizontal_bottom horizontal_top horizontal_middle vertical_left vertical_middle vertical_right];

            y_bottom = 3*ones(1,length(horizontal_bottom));
            y_top = 15*ones(1,length(horizontal_top));
            y_middle = 8*ones(1,length(horizontal_middle));
            y_vertical = 3:1.5:11;  % Adjusted spacing

            yobs = [y_bottom y_top y_middle y_vertical y_vertical y_vertical];
            
            nrO = length(xobs);
            robs = 0.8 * ones(1,nrO);  % Doubled obstacle size
            xt = 14;
            yt = 14;
            lb = 0;
            ub = 17;
            NumberofPoints = 5;
            T = 500;
            N = 50;
        case 9
            nrO = 60;  % Reduced number of obstacles
            xs = 1;
            ys = 1;
            circles = 4;  % Reduced number of circles
            points_per_circle = nrO/circles;
            for i = 1:circles
                theta = linspace(0, 1.8*pi, points_per_circle);
                r = i * 4;  % Increased spacing between circles
                xobs = [xobs 12 + r*cos(theta)];
                yobs = [yobs 12 + r*sin(theta)];
            end
            robs = 0.75 * ones(1,nrO);  % More than doubled obstacle size
            xt = 23;
            yt = 23;
            lb = 0;
            ub = 24;
            NumberofPoints = 8;
            T = 600;
            N = 150;
        case 10
            % Warehouse layout with storage racks, main aisles and workstations

            % Start and goal positions (near entrance and shipping area)
            xs = 2;
            ys = 2;
            xt = 22;
            yt = 22;

            % Generate storage rack rows (6 double-sided rack rows)
            rack_rows = 6;
            obstacles_per_row = 12;
            rack_spacing = 4;  % Space between rack rows for aisles

            % Create double-sided storage racks
            for row = 1:rack_rows
                x_base = 5 + (row-1)*rack_spacing;
                % First side of rack
                x_rack1 = x_base * ones(1, obstacles_per_row);
                y_rack1 = linspace(5, 20, obstacles_per_row);
                % Second side of rack
                x_rack2 = (x_base + 1) * ones(1, obstacles_per_row);
                y_rack2 = linspace(5, 20, obstacles_per_row);

                xobs = [xobs x_rack1 x_rack2];
                yobs = [yobs y_rack1 y_rack2];
            end

            % Add workstations along the walls
            workstation_x = [2*ones(1,4) 8 13 18 23*ones(1,4)];
            workstation_y = [5:4:17 22 22 22 5:4:17];

            % Combine all obstacles
            xobs = [xobs workstation_x];
            yobs = [yobs workstation_y];

            % Set parameters
            nrO = length(xobs);  % Total number of obstacles
            robs = ones(1,nrO) * 0.9;  % Uniform obstacle size

            % Set boundaries
            lb = 0;
            ub = 25;

            % Algorithm parameters
            NumberofPoints = 6;  % More waypoints for complex navigation
            T = 600;  % High number of iterations for better path finding
            N = 300;   % Sufficient number of search agents
        case 11
            % Warehouse layout with storage racks, main aisles and workstations

            % Start and goal positions (forcing path through the warehouse)
            xs = 5;
            ys = 3;
            xt = 27;
            yt = 27;

            % Generate storage rack rows (6 double-sided rack rows)
            rack_rows = 6;
            obstacles_per_row = 8;  % Reduced number of obstacles per row
            rack_spacing = 6;  % Increased space between rack rows for aisles

            % Create double-sided storage racks with larger gaps
            for row = 1:rack_rows
                x_base = 5 + (row-1)*rack_spacing;
                % First side of rack
                x_rack1 = x_base * ones(1, obstacles_per_row);
                y_rack1 = linspace(5, 25, obstacles_per_row);
                % Second side of rack (increased separation within rack)
                x_rack2 = (x_base + 1.5) * ones(1, obstacles_per_row);
                y_rack2 = linspace(5, 25, obstacles_per_row);

                xobs = [xobs x_rack1 x_rack2];
                yobs = [yobs y_rack1 y_rack2];
            end

            % Add blocking walls to force internal routing
            wall_spacing = 3;
            % Top wall
            top_wall_x = linspace(0, 30, 10);
            top_wall_y = 30 * ones(1, 10);
            % Bottom wall
            bottom_wall_x = linspace(0, 30, 10);
            bottom_wall_y = 0 * ones(1, 10);
            % Left wall
            left_wall_x = 0 * ones(1, 10);
            left_wall_y = linspace(0, 30, 10);
            % Right wall
            right_wall_x = 30 * ones(1, 10);
            right_wall_y = linspace(0, 30, 10);

            % Add workstations with adjusted positions
            workstation_x = [3*ones(1,3) 15 22 27*ones(1,3)];
            workstation_y = [8:8:24 27 27 8:8:24];

            % Combine all obstacles
            xobs = [xobs workstation_x top_wall_x bottom_wall_x left_wall_x right_wall_x];
            yobs = [yobs workstation_y top_wall_y bottom_wall_y left_wall_y right_wall_y];

            % Set parameters
            nrO = length(xobs);  % Total number of obstacles
            robs = ones(1,nrO) * 1;  % Slightly larger obstacles

            % Set tight boundaries to prevent external routing
            lb = 0;
            ub = 30;

            % Algorithm parameters
            NumberofPoints = 6;  % More waypoints for complex navigation
            T = 1000;  % High number of iterations for better path finding
            N = 400;   % Sufficient number of search agents
        
        otherwise
            nrO = 45;
            xs=3;
            ys=3;
            xobs = [4 4 4 4 4 4 4 4 4 6 6 6 6 6 6 6 6 6 8 8 8 8 8 8 8 8 8 10 10 10 10 10 10 10 10 10 12 12 12 12 12 14 14 14 14];
            yobs = [3 3.5 4 4.5 5 5.5 6 6.5 7 8 8.5 9 9.5 10 10.5 11 11.5 12 1 1.5 2 2.5 3 3.4 4 4.5 5 6 6.5 7 7.5 8 8.5 9 9.5 10 10 10.5 11 11.5 12 10 10.5 11 11.5];
            robs = [0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4 0.4];
            xt = 15;
            yt = 15;
            lb = -1;
            ub = 19;
            NumberofPoints = 4;
            T=400; % Maximum number of iterations
            N=30; % Number of search agents
    end
    
    model.xs=xs;
    model.ys=ys;
    model.xt=xt;
    model.yt=yt;
    model.xobs=xobs;
    model.yobs=yobs;
    model.robs=robs;
    model.n=nrO;
end