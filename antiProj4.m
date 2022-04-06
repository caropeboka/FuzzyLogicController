if ~isempty(instrfind)
        fclose(instrfind);
        delete(instrfind);
end

%set port and baudra



arduino=serial('COM6', 'BAUD', 9600);
fopen(arduino);

while 1
    input = fscanf(arduino, '%s'); %membaca serial pada arduino
    data = strsplit(input,';');
    
    sensorA = str2num(data{1:1});
    %pause(2);
    sensorB = str2num(data{2:2});
    
    fis = readfis('antiTabrakan');
    output = evalfis([sensorA sensorB],fis)
    
    if(output >= 00 && output <=10 )
        fwrite(arduino,1);
        fprintf('value sensorA : %d |', sensorA);
        fprintf('value sensorB : %d \n', sensorB);
        fprintf('Condition : Servo normal\n\n');
    else
        fwrite(arduino,0);
        fprintf('value sensorA : %d |', sensorA);
        fprintf('value sensorB : %d \n', sensorB);
        fprintf('Condition : Servo Triggered\n\n');
    end
end
fclose(arduino);
delete(arduino);