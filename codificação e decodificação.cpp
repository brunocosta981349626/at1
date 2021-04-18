#include <string>
#include <iostream>

using namespace std;

int main() 
{
	char numeros[] = { '0','1','2','3','4','5','6','7','8','9' };
	char numerosC[] = { 'A','B','C','D','E','F','G','H','I','J' };

	while (true) {
		std::string funcao;
		std::string texto;
		std::string processo;
		std::string saida;

		cout << "C > Codificar | D > Decodificar\n";
		cin >> funcao;
		if (funcao == "C") {
			cin >> texto;

			char lastChar = { 0 };
			int charCount = 0;
			int counter = 0;

			for (char c : texto)
			{
				counter = 0;
				if (c == 'Z')
				{
					processo = processo + 'Z' + 'Z';
				}
				else if (isdigit(c)){
					for (char n : numeros)
					{
						if (c == n)
						{
							processo = processo + 'Z' + numerosC[counter];
						}
						counter++;
					}
				}
				else {
					processo = processo + c;
				}
			}

			int contadorDeChar = 0;

			for (char c: processo)
			{
				if (c == lastChar) 
				{
					charCount++;
				}
				else if (lastChar == '\0') 
				{
					charCount = 1;
					lastChar = c;
				}
				else if (c != lastChar) 
				{
					if (charCount > 1)
					{
						saida = saida + std::to_string(charCount);
					}
					saida = saida + lastChar;
					lastChar = c;
					charCount = 1;
				}
				else if (c != lastChar && charCount > 1) 
				{
					if (charCount > 1) 
					{
						saida = saida + std::to_string(charCount);
					}
					saida = saida + c;
					lastChar = c;
					charCount = 1;
				}

				contadorDeChar++;
				if (contadorDeChar == processo.size())
				{
					if (charCount > 1)
					{
						saida = saida + std::to_string(charCount);
					}
					saida = saida + c;
				}
			}

			cout << saida << endl;
		}
		else if (funcao == "D") {
			cin >> texto;
			std::string saidaAux;
			std::string saida;
			int textoLen = texto.size();

			int contadorDeChar = 0;
			int i;
			for (i = 0; i < textoLen; i++)
			{
				if (isdigit(texto[i]))
				{
					int digit = texto[i] - '0';
					int j;
					for (j = 0; j < digit; j++)
					{
						saidaAux = saidaAux + texto[contadorDeChar + 1];
					}
					contadorDeChar++;
				}
				else
				{
					saidaAux = saidaAux + texto[contadorDeChar];
				}
				contadorDeChar++;
			}

			int saidaLen = saidaAux.size();

			for (i = 0; i < saidaLen; i++)
			{
				if (saidaAux == "Z") break;
				if (saidaAux[i] == 'Z' && saidaAux[i + 1] == 'Z')
				{
					saida = saida + 'Z';
					i++;
				}
				else
				{
					int contador = 0;
					for (char c : numerosC) 
					{
						if (saidaAux[i] == 'Z' && saidaAux[i + 1] == c)
						{
							saida = saida + numeros[contador];
							i++;
							break;
						}
						contador++;
						if (contador == 10)
						{
							saida = saida + saidaAux[i];
						}
					}
				}
			}

			cout << saida << endl;
		}
		else {
			cout << "\n";
		}
	}
}