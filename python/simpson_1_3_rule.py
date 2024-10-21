def simpson_1_3_rule(f, a, b, n):
    """
    Método de Simpson 1/3 para integração numérica.
    
    Args:
        f (function): Função a ser integrada.
        a (float): Limite inferior de integração.
        b (float): Limite superior de integração.
        n (int): Número de subintervalos (deve ser par).
    
    Returns:
        float: Aproximação da integral de f de a até b.
    """
    if n % 2 == 1:
        raise ValueError("O número de subintervalos (n) deve ser par.")
    
    h = (b - a) / n
    integral = f(a) + f(b)
    
    for i in range(1, n, 2):
        integral += 4 * f(a + i * h)
    
    for i in range(2, n, 2):
        integral += 2 * f(a + i * h)
    
    integral *= h / 3
    return integral
