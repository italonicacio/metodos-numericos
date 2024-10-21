import numpy as np

import numpy as np

class LinearLeastSquares:
    def __init__(self):
        self.m = None
        self.c = None

    def fit(self, x, y):
        """
        Método de mínimos quadrados para ajuste linear.
        
        Args:
            x (np.ndarray): Array de valores x.
            y (np.ndarray): Array de valores y.
        
        Returns:
            None
        """
        # Construir a matriz A
        A = np.vstack([x, np.ones(len(x))]).T
        
        # Resolver o sistema de equações normais A.T * A * coeffs = A.T * y
        ATA = np.dot(A.T, A)
        ATy = np.dot(A.T, y)
        coeffs = np.linalg.solve(ATA, ATy)
        
        self.m, self.c = coeffs[0], coeffs[1]

    def evaluate(self, x):
        """
        Usa os coeficientes ajustados para prever novos valores de y.
        
        Args:
            x (np.ndarray): Array de valores x.
        
        Returns:
            np.ndarray: Valores previstos de y.
        """
        if self.m is None or self.c is None:
            raise ValueError("The model has not been fitted yet.")
        return self.m * x + self.c
    
    def evaluate_one(self, x):
        """
        Usa os coeficientes ajustados para prever um único valor de y.
        
        Args:
            x (float): Um único valor x.
        
        Returns:
            float: Valor previsto de y.
        """
        if self.m is None or self.c is None:
            raise ValueError("The model has not been fitted yet.")
        return self.m * x + self.c
            