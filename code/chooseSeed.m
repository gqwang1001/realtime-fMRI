function [answer] = chooseSeed(X)
% create a dialog to choose seeds
            f_slices = figure('Position', [500, 500, 1000, 800]);
            subplot(2,3,1)
            imagesc(X(:,:,24));colormap(gray);
            title(24);
            
            subplot(2,3,2)
            imagesc(X(:,:,25));colormap(gray);
            title(25);
            
            subplot(2,3,3)
            imagesc(X(:,:,26));colormap(gray);
            title(26);
            
            subplot(2,3,4)
            imagesc(X(:,:,27));colormap(gray);
            title(27);
            
            subplot(2,3,5)
            imagesc(X(:,:,28));colormap(gray);
            title(28);
            
            subplot(2,3,6)
            imagesc(X(:,:,29));colormap(gray);
            title(29);
            
            pause;
            
            prompt = {'Choose the slice'};
            dlgtitle='Input';
            ans_slice = inputdlg({'Right Motor Cortex', 'Left Motor Cortex'},...
                'Choice of Slice',...
                [1 80; 1 80] );
            close(f_slices);
            
            %pick motor cortex hires
            
            f_slice = figure('Position', [500, 500, 500, 500]);
            imagesc(X(:,:,str2num(ans_slice{1,1})));
            title(['Slice ', ans_slice{1,1},' (Right Motor Cortex)']);
            colormap(gray);
            u1 = drawcrosshair;
            pause;
            answer = cell(6,1);
            answer{1,1} = num2str(round(u1.Position(2)));
            answer{2,1} = num2str(round(u1.Position(1)));
            answer{3,1} = ans_slice{1,1};
            close(f_slice);
            
            f_slice1 = figure('Position', [500, 500, 500, 500]);
            imagesc(X(:,:,str2num(ans_slice{2,1})));
            title(['Slice ', ans_slice{2,1},' (Left Motor Cortex)']);
            colormap(gray);
            u2 = drawcrosshair;
            pause;
            answer{4,1} = num2str(round(u2.Position(2)));
            answer{5,1} = num2str(round(u2.Position(1)));
            answer{6,1} = ans_slice{2,1};
            close (f_slice1);
end

