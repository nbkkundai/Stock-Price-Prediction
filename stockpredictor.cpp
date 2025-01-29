#include <iostream>
#include <vector>
#include <limits>
#include <cmath> 

using namespace std;

class StockPredictor {
private:
    vector<double> prices;
    double weight;
    double learning_rate;

public:
    StockPredictor(double lr = 0.01) : weight(1.0), learning_rate(lr) {}

    void addPrice(double price) {
        prices.push_back(price);
    }

    void train(int epochs = 1000) {
        int n = prices.size();
        if (n < 2) {
            cout << "Not enough data to train. Enter at least 2 prices." << endl;
            return;
        }

        for (int i = 0; i < epochs; ++i) {
            double gradient = 0.0;
            for (size_t j = 0; j < n - 1; ++j) {
                double predicted = weight * prices[j];
                double error = predicted - prices[j + 1];
                gradient += error * prices[j];
            }

            if (n > 0) {
                weight -= learning_rate * (gradient / n);
            }

            // Prevent weight from going into NaN territory
            if (isnan(weight) || isinf(weight)) {
                weight = 1.0;
                cout << "Warning: Unstable weight detected. Resetting model." << endl;
                break;
            }
        }
        cout << "Training complete. Model weight: " << weight << endl;
    }

    double predict(double last_price) {
        return weight * last_price;
    }
};

int main() {
    StockPredictor predictor;
    int num_prices;
    
    // Get number of historical prices
    cout << "Enter the number of historical prices: ";
    while (!(cin >> num_prices) || num_prices < 2) {
        cout << "Invalid input. Enter an integer (at least 2): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Get historical prices
    cout << "Enter " << num_prices << " historical stock prices:\n";
    for (int i = 0; i < num_prices; ++i) {
        double price;
        while (!(cin >> price)) {
            cout << "Invalid input. Enter a valid number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        predictor.addPrice(price);
    }

    // Train the model
    cout << "Training model...\n";
    predictor.train();

    // Get last known price for prediction
    double last_price;
    cout << "Enter the last known price: ";
    while (!(cin >> last_price)) {
        cout << "Invalid input. Enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Predict next price
    cout << "Predicted next price: " << predictor.predict(last_price) << endl;

    return 0;
}
