function [LeftX, RightX] = updateplot_timeSeries(sAXs, fill_s, line_s, window_width, Mval, norMval, norMvaldetrend)

            Tidx = size(Mval,1);
            set(line_s{1,1}, {"YData"}, {Mval(:,1); Mval(:,2)});
            LeftX = max(1, Tidx - window_width); RightX = Tidx;
            FloorY = min(sAXs{1,1}.YLim); CeilY = max(sAXs{1,1}.YLim);
            set(fill_s{1,1}, "Vertices", [LeftX, LeftX, RightX, RightX; FloorY, CeilY, CeilY, FloorY]');
            sAXs{1,1}.Title.String = ['Raw Signal (Correlation = ' num2str(corr(Mval(LeftX: RightX, 1),Mval(LeftX: RightX,2))) ')'];
            drawnow
            
            set(line_s{2,1},{"YData"}, {norMval(:,1); norMval(:,2)});
            FloorY = min(sAXs{2,1}.YLim); CeilY = max(sAXs{2,1}.YLim);
            set(fill_s{2,1}, "Vertices", [LeftX, LeftX, RightX, RightX; FloorY, CeilY, CeilY, FloorY]');
            sAXs{2,1}.Title.String = ['Normalized Signal (Correlation = ' num2str(corr(norMval(LeftX: RightX,1),norMval(LeftX: RightX,2))) ')'];
            drawnow
            
            set(line_s{3,1}, {"YData"}, {norMval(:,1); norMval(:,2)});
            FloorY = min(sAXs{3,1}.YLim); CeilY = max(sAXs{3,1}.YLim);
            set(fill_s{3,1}, "Vertices", [LeftX, LeftX, RightX, RightX; FloorY, CeilY, CeilY, FloorY]');
            sAXs{3,1}.Title.String = ['Detrended Signal (Correlation = ' num2str(corr(norMvaldetrend(LeftX: RightX,1),norMvaldetrend(LeftX: RightX,2))), ')'];
            drawnow
            
end

