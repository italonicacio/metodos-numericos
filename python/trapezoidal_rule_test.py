import pytest
from trapezoidal_rule import trapezoidal_rule

def test_trapezoidal_rule():
    # Definindo a função a ser integrada
    def f(x):
        return x**2
    
    # Limites de integração
    a = 0
    b = 1
    
    # Número de subintervalos
    n = 100
    
    # Calculando a integral
    result = trapezoidal_rule(f, a, b, n)
    
    # Valor esperado da integral de x^2 de 0 a 1 é 1/3
    expected = 1/3
    
    assert abs(result - expected) < 1e-4
