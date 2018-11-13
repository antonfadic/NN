# Writing a fully connected multilayer perceptron from Matlab into C

Why would you want to do this? First of all, performance. Matlab can be very helpful for some things, such as computing the weights of the neural network, but if you want to have full speed, then you need it written in a lower level language. In this case I chose C, and I compiled it using gcc 4.8.

Second reason, if you want to use Fluent with UDF, this is the way to go. Fluent is written in C and the UDF give you almost all the capabilities of the language. On windows the optimizations are limited, but if you execute Fluent from Linux, all the capabilities are available.

### How do I run it?
The C code does not need anything other than the configuration files. This can be found in example.m, where a simple neural network is computed and then the parameters are exported. 

## To do

Bug testing. For now I tested for memory leakages and I removed all the ones I have found. I tested it with different architectures such as different number of layers and different number of neurons per layer. So far the results have been consistent. A possible improvement is to change the activation function as a function of the layer or explore with more exotic architectures.

## Author

* **Anton Fadic** 

## License

You are free to use any of these codes if you acknowledge the source. 
