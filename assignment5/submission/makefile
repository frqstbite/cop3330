neuralnetwork: driver.o NeuralNetwork.o Block.o LinearLayer.o ReLUActivation.o Module.o
	g++ driver.o NeuralNetwork.o Block.o LinearLayer.o ReLUActivation.o Module.o -o neuralnetwork

driver.o: driver.cpp NeuralNetwork.h
	g++ -c driver.cpp NeuralNetwork.h

NeuralNetwork.o: NeuralNetwork.cpp NeuralNetwork.h
	g++ -c NeuralNetwork.cpp NeuralNetwork.h

Block.o: Block.cpp Block.h LinearLayer.h ReLUActivation.h
	g++ -c Block.cpp Block.h LinearLayer.h ReLUActivation.h

LinearLayer.o: LinearLayer.cpp LinearLayer.h Module.h
	g++ -c LinearLayer.cpp LinearLayer.h Module.h

ReLUActivation.o: ReLUActivation.cpp ReLUActivation.h Module.h
	g++ -c ReLUActivation.cpp ReLUActivation.h Module.h

Module.o: Module.cpp Module.h
	g++ -c Module.cpp Module.h
