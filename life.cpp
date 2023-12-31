#include<iostream>

bool** createTable(int height, int width){
	bool** table = new bool*[height];
	for(int i = 0; i < height; i++){
		table[i] = new bool[width];
	}
	return table;
}

void deleteTable(bool** table, int height){
	for(int i = 0; i < height; i++){
		delete[] table[i];
	}
	delete[] table;
}

void printTable(bool** table, int height, int width){
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			std::cout << table[i][j];
		}
		std::cout << std::endl;
	}
}

struct point{
	int x = 0;
	int y = 0;
};

point createPoint(int x, int y){
	point p;
	p.x = x;
	p.y = y;
	return p;
};

bool getValue(bool** table, int height, int width, point p){
	return table[(height + p.y % height) % height][(width + p.x % width) % width];
}

void setCell(bool** table,  point p){
	table[p.y][p.x] = true;
}

void setTable(bool** table){
	int cellsNumber = 0;
	point p;
	std::cout << "Enter number of cells alive, which you want to set in this game" << std::endl;
	std::cin >> cellsNumber;
	for(int i = 0; i < cellsNumber; i++){
		std::cout << "Enter non negative integer x and y coordinates of " << i + 1 << " cell alive, split by space" << std::endl;
		std::cin >> p.x >> p.y;
		setCell(table, p);
	}
	std::cout << std::endl;
}

int getNeighboursNumber(bool** table, int height, int width, point p){
        int count = 0;
        point iterable;
        iterable.x = p.x - 1;
        for(int i = 0; i < 3; i++){
                iterable.y = p.y - 1;
                for(int j = 0; j < 3; j++){
                        if( !(i == j && j == 1) && getValue(table, height, width, iterable)){
                                count++;
                        }
                iterable.y++;
                }
        iterable.x++;
        }
        return count;
}

bool nextStepCell(bool** table, int height, int width, point p){
        int neighbourNumber = getNeighboursNumber(table, height, width, p);
        if(getValue(table, height, width, p)){
                if(neighbourNumber == 2 || neighbourNumber == 3){
                        return 1;
                }
                else{
                        return 0;
                }
        }
        else{
                if(neighbourNumber == 3){
                        return 1;
                }
                else{
                        return 0;
                }
        }
}

void doNextStep(bool** table, int height, int width){
	bool** tmp  = createTable(height, width);
	point p = createPoint(0, 0);
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(table[i][j]){
				tmp[i][j] = true;
			}
			else{
				tmp[i][j] = false;
			}
		}
	}
	std::cout << std::endl;
	for(int i = 0; i < height; i++){
        	p.y = i;
        	for(int j = 0; j < width; j++){
                	p.x = j;
                	table[i][j] = nextStepCell(tmp, height, width, p);
        	}
        }
	deleteTable(tmp, height);
}

struct tableCache{
	int cacheSize;
	unsigned long long* cache;
};

bool cacheEquals(tableCache cache1, tableCache cache2){
	if(cache1.cacheSize == cache2.cacheSize){
		for(int i = 0; i < cache1.cacheSize; i++){
			if (cache1.cache[i] != cache2.cache[i]){
				return false;
			}
		}
		return true;
	}
	return false;
}

tableCache stepIntoCache(bool** table, int height, int width){
	tableCache result;
	const int bufferSize = 8 * sizeof(unsigned long long);
	const int tableSize = height * width;
	result.cacheSize = tableSize / bufferSize;
	if(tableSize % bufferSize != 0){
		result.cacheSize++;
	}
	result.cache = new unsigned long long[result.cacheSize];
	int count = 0;
	int bufferNumber = 0;
	unsigned long long tmp = 0;
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(table[i][j]){
				tmp++;
			}
			tmp *= 2;
			count++;
			if(count == bufferSize){
				count = 0;
				result.cache[bufferNumber] = tmp;
				tmp = 0;
				bufferNumber++;
			}
		}
	}
	result.cache[bufferNumber] = tmp;
	return result;
}

void doGame(bool** table, int height, int width){
	int step = 0;
	bool check = false;
	tableCache* allCache = new tableCache[10000];
	std::cout << "Step " << step << std::endl;
	printTable(table, height, width);
	allCache[step] = stepIntoCache(table, height, width);
	while(true){
		if(step == 15){
			std::cout << "game is too long" << std::endl;
			break;
		}
		step++;
		doNextStep(table, height, width);
		allCache[step] = stepIntoCache(table, height, width);
		for(int i = 0; i < step; i++){
			if(cacheEquals(allCache[step], allCache[step - i - 1])){
				std::cout << "Step " << step << std::endl;
				printTable(table, height, width);
	       	        	std::cout << "Game ends because of repeating position on gamefield" << std::endl;
                	        check = true;
				break;
                       	}
		}
		if(check){
			break;
		}
		std::cout << "Step " << step << std::endl;
		printTable(table, height, width);
	}
	std::cout << "Game ended on step " << step << std::endl;
	for(int i = 0; i < 10000; i++){
		delete[] allCache[i].cache;
	}
	delete[] allCache;
}



int main(){
	std::cout << "Welcome to the game life" << std::endl;
	std::cout << "Enter height and width of gameboard split by space" << std::endl;
	int height;
	int width;
	std::cin >> height >>  width;

	bool** field = createTable(height, width);

	setTable(field);

	doGame(field, height, width);

	deleteTable(field, height);
	return 0;
}
