#include <iostream>

using namespace std;

int main() {
	int numberOfCases;
	scanf("%d", &numberOfCases);

	for (int i = 0; i < numberOfCases; i++) {
		int numberOfNonNativeTurtles = 0;
		int previousNumberOfTurtles = 1;
		int currentNumberOfTurtles;
		while (scanf("%d",  &currentNumberOfTurtles) && currentNumberOfTurtles != 0) {
			if (currentNumberOfTurtles > 2 * previousNumberOfTurtles) {
				numberOfNonNativeTurtles += currentNumberOfTurtles - 2 * previousNumberOfTurtles;
			}
			previousNumberOfTurtles = currentNumberOfTurtles;
		}
		printf("%d\n", numberOfNonNativeTurtles);
	}
	return 0;
}