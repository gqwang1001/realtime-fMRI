function vol_q = rt_slice_time_correction(volRaw, slice_times, slice_indices, tr, update)
% Calculate the slice time correction

% Created by Guoqing Wang, 08/05/2020
nt = size(volRaw,2);
if update == 0
    Ts_q = tr*(1:nt);
    vol_q = zeros(size(volRaw));
    for j = 1: length(slice_times)
        ind = find(slice_indices == j);
        if ~isempty(ind)
            for k = 1:length(ind)
                Ts = Ts_q + slice_times(j);
                vol_q(ind(k),:) = interp1(Ts, volRaw(ind(k),:), Ts_q, 'spline');
            end
        end
    end

else
    
    Ts_q = tr*size(volRaw, 2);
    vol_q = zeros(size(volRaw,1),1);
    for j = 1: length(slice_times)
        ind = find(slice_indices == j);
        if ~isempty(ind)
            for k = 1:length(ind)
                Ts = tr * (1:nt) + slice_times(j);
                vol_q(ind(k)) = interp1(Ts, volRaw(ind(k),:), Ts_q, 'spline');
            end
        end
    end
end
    

end

