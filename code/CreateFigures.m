function [f1, f2, f3,sAXs, fill_s, line_s, f2subplots, f3subplots] = CreateFigures(imINIT)
% create figures

f1 = figure(1);
f1.Position =  [200, 500, 500, 500];
f1.Name = 'Time Series';
set(gca, 'xlimmode','manual','ylimmode','manual','zlimmode','manual',...
    'climmode','manual','alimmode','manual');
set(f1,'doublebuffer','off');
% s3 = subplot(3,1,3); im3 = imagesc(0); colorbar; axis off;
% set(s3, 'CLim', [-1, 1]);
% s3.Colormap = colormap(jet);
% s3.Title.String = 'corr';

sAXs = {};
fill_s = {};
line_s = {};
for i = 1:3
    sAXs{i,1} = subplot(3,1,i);
    fill_s{i,1} = fill(sAXs{i,1}, [1,1,2,2], [0,1e-6, 1e-6, 0], 'y', "FaceAlpha", .1);
    hold on;
    line_s{i,1} = plot(sAXs{i, 1}, zeros(3,2));
    hold off;
end

% legend(s3, 'right', 'left', 'Location','SouthOutside', 'Orientation', 'horizontal');
set(f1,'visible','off');


f2 = figure(2);
f2.Position =  [1000, 500, 1200, 800];
f2.Name = 'Correlation Map';
f2subplots = {};
f2axs = {};
set(f2,'visible','off');

for fig = 1:12
    f2axs{fig,1} = subplot(3,4, fig);
    f2subplots{fig, 1} = imagesc(f2axs{fig,1}, imINIT(:,:,2*fig+7));
    title(f2axs{fig,1}, ['Slice ', num2str(2*fig+7)]);
    colormap(f2axs{fig,1}, 'jet'); colorbar(f2axs{fig,1}); caxis(f2axs{fig,1},[-1,1]);
end


f3 = figure(3);
f3.Position =  [1000, 500, 1200, 800];
f3.Name = 'IC Map';
f3subplots = {};
f3axs = {};
set(f3,'visible','off');

for fig = 1:12
    f3axs{fig,1} = subplot(3,4, fig);
    f3subplots{fig, 1} = imagesc(f3axs{fig,1}, imINIT(:,:,2*fig+7));
    title(f3axs{fig,1}, ['IC ', num2str(fig)]);
    colormap(f3axs{fig,1}, 'jet'); colorbar(f3axs{fig,1});
    %     caxis(f3axs{fig,1},[2,5]);
end
end

