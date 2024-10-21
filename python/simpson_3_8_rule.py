def simpson_3_8_rule(f, a, b, n):
    """
    Método de Simpson 3/8 para integração numérica.
    
    Args:
        f (function): Função a ser integrada.
        a (float): Limite inferior de integração.
        b (float): Limite superior de integração.
        n (int): Número de subintervalos (deve ser múltiplo de 3).
    
    Returns:
        float: Aproximação da integral de f de a até b.
    """
    if n % 3 != 0:
        raise ValueError("O número de subintervalos (n) deve ser múltiplo de 3.")
    
    h = (b - a) / n
    integral = f(a) + f(b)
    
    for i in range(1, n):
        if i % 3 == 0:
            integral += 2 * f(a + i * h)
        else:
            integral += 3 * f(a + i * h)
    
    integral *= 3 * h / 8
    return integral
