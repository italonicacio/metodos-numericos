def trapezoidal_rule(f, a, b, n):
    """
    Método do Trapézio para integração numérica.
    
    Args:
        f (function): Função a ser integrada.
        a (float): Limite inferior de integração.
        b (float): Limite superior de integração.
        n (int): Número de subintervalos.
    
    Returns:
        float: Aproximação da integral de f de a até b.
    """
    h = (b - a) / n
    integral = 0.5 * (f(a) + f(b))
    
    for i in range(1, n):
        integral += f(a + i * h)
    
    integral *= h
    return integral
