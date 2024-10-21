import numpy as np
import pytest
from quadratic_least_squares import QuadraticLeastSquares

def test_fit():
    x = np.array([1, 2, 3, 4, 5])
    y = np.array([1, 4, 9, 16, 25])
    model = QuadraticLeastSquares()
    model.fit(x, y)
    assert round(model.a, 2) == 1.00
    assert round(model.b, 2) == 0.00
    assert round(model.c, 2) == 0.00

def test_evaluate_array():
    x = np.array([1, 2, 3, 4, 5])
    y = np.array([1, 4, 9, 16, 25])
    model = QuadraticLeastSquares()
    model.fit(x, y)
    x_new = np.array([6, 7, 8])
    y_pred = model.evaluate(x_new)
    y_expected = np.array([36, 49, 64])
    assert np.allclose(y_pred, y_expected, atol=0.1)

def test_evaluate_single_value():
    x = np.array([1, 2, 3, 4, 5])
    y = np.array([1, 4, 9, 16, 25])
    model = QuadraticLeastSquares()
    model.fit(x, y)
    single_x = 6
    single_y_pred = model.evaluate(single_x)
    single_y_expected = 36
    assert round(single_y_pred, 1) == round(single_y_expected, 1)
