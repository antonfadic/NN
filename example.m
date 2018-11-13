x = [0 0; 0 1; 1 0; 1 1];
y = [0 -2.2 2.02 0];

[xn, xs] = mapminmax(x'); xn = xn';
[yn, ys] = mapminmax(y);

nLayers = 1;
%netSize = 4*ones(1,nLayers);
netSize = [12 12 12 12 12 12];

net = fitnet(netSize);

net.divideParam.trainRatio = 1;
net.divideParam.valRatio = 0;
net.divideParam.testRatio = 0;

%net.inputs{1}.processFcns = {'mapminmax','removeconstantrows'};
%net.outputs{1}.processFcns = {'mapminmax','removeconstantrows'};
net.inputs{1}.processFcns = {};
net.outputs{1}.processFcns = {};

net = train(net,xn',yn);
%%
p=net(xn');
mapminmax.reverse(p,ys)
%%
xx = xn(2,:)'

b1 = net.b{1};
w1 = net.IW{1};

L1 = (w1*xx+b1)

b2 = net.b{2};
w2 = net.LW{2,1};
 
L2 = (w2*L1+b2);
% 
% w3 = net.LW{3,2};
% b3 = net.b{3};
% 
% L3 = tansig(w3*L2 + b3);
% 
% w4 = net.LW{4,3};
% b4 = net.b{4};
% 
% L4 = (w4*L3 + b4);

%mapminmax.reverse(L2,ys)

%% generate configuration file

totalW = length(getwb(net));
hiddenL = length(netSize);
nL = netSize;
L0 = length(x(1,:));
Lout = length(y(:,1));

config = [totalW hiddenL L0 nL];

fid = fopen('config.bin','wb');
fwrite(fid, config,'integer*4'); %in binary, integer has 4 bytes
fclose(fid);
% read config file

fid = fopen('config.bin', 'rb');
fread(fid, 10, 'integer*4')
fclose(fid);
% generate data file
outFile = [];

%for i=1:2 %number of biases = sum(inputs, L1, L2, ..., Ln, O)
%    outFile = [outFile net.b{i}];
%end

outFile = getwb(net);

fid = fopen('weights.bin','wb');
fwrite(fid, outFile,'double'); %in binary, integer has 4 bytes
fclose(fid);

%

fid = fopen('weights.bin', 'rb');
fread(fid, 100, 'double')
fclose(fid);

% store min max y

yLimits = [min(y), max(y)];

fid = fopen('yLimits.bin','wb');
fwrite(fid, yLimits,'double'); %in binary, integer has 4 bytes
fclose(fid);

%  read min max y

fid = fopen('yLimits.bin', 'rb');
fread(fid, 100, 'double')
fclose(fid);

% store min max x
%first x1min x1max; x2min x2max and so on

xLimits = [];

for i=1:L0
    xLimits = [xLimits min(x(:,i))];
    xLimits = [xLimits max(x(:,i))];
end

fid = fopen('xLimits.bin','wb');
fwrite(fid, xLimits,'double'); %in binary, integer has 4 bytes
fclose(fid);

%

fid = fopen('xLimits.bin', 'rb');
fread(fid, 100, 'double')
fclose(fid);