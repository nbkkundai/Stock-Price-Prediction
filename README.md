# Stock Predictor (C++) 

## Description
This is a simple command-line stock price prediction tool implemented in C++. It uses gradient descent to model the relationship between historical stock prices and predicts future stock prices. The program handles unstable weight situations (NaN or infinity) and resets the model if necessary. 

## Features
- Input historical stock prices.
- Train a linear model using gradient descent.
- Predict the next stock price based on the trained model.
- Handles NaN or infinite values in the model and resets if unstable weights are detected. 

## How to Use
1. Compile the program using a C++ compiler, e.g., g++:
   ```sh
   g++ stock_predictor.cpp -o stock_predictor -std=c++11
## Example run 
   Enter the number of historical prices: 5
   Enter 5 historical stock prices:
   100
   105
   110
   115
   120
   Training model...
   Training complete. Model weight: 0.95
   Enter the last known price: 130
   Predicted next price: 123.5 
## Example run 
- C++ compiler (e.g., g++)
- Terminal or command prompt
  
## Future Improvements
- Implement a more complex machine learning model.
- Add functionality to handle larger datasets and perform more sophisticated analyses.
- Implement persistent storage to save historical data.
  
## License
This project is open-source and free to use for educational purposes.

## Author
Developed by Nqobani Ncube.
