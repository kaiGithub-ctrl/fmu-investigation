import fmpy
import plotly
from fmpy import *
# m, k, b = 5, 0.5, 0.1
fmu = 'Rectifier.fmu'
dump(fmu)
result = simulate_fmu(fmu)
from fmpy.util import plot_result
plot_result(result)