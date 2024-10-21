import numpy as np

class QuadraticLeastSquares:
    def __init__(self):
        self.a = None
        self.b = None
        self.c = None

    def fit(self, x, y):
        """
        Método de mínimos quadrados para ajuste quadrático.
        
        Args:
            x (np.ndarray): Array de valores x.
            y (np.ndarray): Array de valores y.
        
        Returns:
            None
        """
        # Construir a matriz A para ajuste quadrático
        A = np.vstack([x**2, x, np.ones(len(x))]).T
        
        # Resolver o sistema de equações normais A.T * A * coeffs = A.T * y
        ATA = np.dot(A.T, A)
        ATy = np.dot(A.T, y)
        coeffs = np.linalg.solve(ATA, ATy)
        
        self.a, self.b, self.c = coeffs[0], coeffs[1], coeffs[2]

    def evaluate(self, x):
        """
        Usa os coeficientes ajustados para prever novos valores de y.
        
        Args:
            x (np.ndarray or float): Array de valores x ou um único valor x.
        
        Returns:
            np.ndarray or float: Valores previstos de y.
        """
        if self.a is None or self.b is None or self.c is None:
            raise ValueError("The model has not been fitted yet.")
        return self.a * x**2 + self.b * x + self.c
