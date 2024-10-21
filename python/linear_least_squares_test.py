import numpy as np
import pytest
from linear_least_squares import LinearLeastSquares

def test_fit():
    x = np.array([0, 1, 3, -1, 2])
    y = np.array([1, 3, 5, 4, -2])
    model = LinearLeastSquares()
    model.fit(x, y)
    assert round(model.m, 2) == -0.1
    assert round(model.c, 2) == 2.3

def test_evaluate_array():
    x = np.array([0, 1, 3, -1, 2])
    y = np.array([1, 3, 5, 4, -2])
    model = LinearLeastSquares()
    model.fit(x, y)
    
    y_pred = model.evaluate(x)
    y_expected = np.array([2.3, 2.2, 2.0, 2.4, 2.1])
    assert np.allclose(y_pred, y_expected, atol=0.1)

def test_evaluate_single_value():
    x = np.array([0, 1, 3, -1, 2])
    y = np.array([1, 3, 5, 4, -2])
    model = LinearLeastSquares()
    model.fit(x, y)
    single_x = 1
    single_y_pred = model.evaluate_one(single_x)
    single_y_expected = 2.2
    assert round(single_y_pred, 1) == round(single_y_expected, 1)

	
