import pytest
from simpson_1_3_rule import simpson_1_3_rule

def test_simpson_1_3_rule():
    # Definindo a função a ser integrada
    def f(x):
        return x**2
    
    # Limites de integração
    a = 0
    b = 1
    
    # Número de subintervalos (deve ser par)
    n = 100
    
    # Calculando a integral
    result = simpson_1_3_rule(f, a, b, n)
    
    # Valor esperado da integral de x^2 de 0 a 1 é 1/3
    expected = 1/3
    
    assert abs(result - expected) < 1e-4
