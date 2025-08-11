programa
{
	
	funcao inicio()
	{
		real jan, fev, mar, abr, media
		escreva("Vendas mês de janeiro: ")
		leia(jan)
		escreva("Vendas mês de fevereiro: ")
		leia(fev)
		escreva("Vendas mês de março: ")
		leia(mar)
		escreva("Vendas mês de abril: ")
		leia(abr)
		media = (jan + fev + mar + abr)/4
		escreva("\nA média de vendas foi: ", media)
		se (media>5000){ 
			escreva ("\nSeu abono será 10%")}
		senao{
			escreva("\nSeu abono será 3%")}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 70; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */