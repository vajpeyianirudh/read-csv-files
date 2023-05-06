#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/* The third argument has default value 0 which means all the values will be read
if x = 1, then first row of the csv file will be ignored becausethey can be headers
if x = 2, then first two rows of the csv file will be ignored*/ 

void read_csv(std::string filename, std::vector<std::vector<float>> &csv_data, int x = 0);

int main(){
    std::string file_name = "csvfile/sampleCSVFile.csv";
    std::vector<std::vector<float>> csv_data;
    read_csv(file_name, csv_data, 1);
    std::cout << "The size of the data rows is " << csv_data.size() << std::endl;
    std::cout << "The size of the data columns is " << csv_data[0].size() << std::endl;
    std::cout << "The element of the data is: " << csv_data[10][2] << std::endl;

    return 0;
}

void read_csv(std::string filename, std::vector<std::vector<float>> &csv_data, int x){
    std::ifstream csv_file(filename);

    if(csv_file.is_open()){
        float csv_field;
        std::vector<float> csv_row;
        std::string line, field;
        std::vector<std::vector<std::string>> data;

        while(getline(csv_file,line)){
            std::vector<std::string> row;
            std::stringstream ss(line);

            while(getline(ss, field, ',')){
                row.push_back(field);
            }
            data.push_back(row);
        }
        csv_file.close();
        for (int i = x; i < data.size(); i++){
            for (int j = 0; j < data[0].size(); j++){
                csv_field = std::stof(data[i][j]);
                csv_row.push_back(csv_field);
            }
            csv_data.push_back(csv_row);
            csv_row.clear();
        }
    }
    else{
        std::cout << "Error opening file: " << filename << std::endl;
    }
}