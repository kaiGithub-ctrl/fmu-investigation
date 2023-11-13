import fmpy
from fmpy import plot_result
from fmpy.util import plot_result
from fmpy.fmi2 import FMU2Slave
from fmpy import *

from pathlib import Path

from random_bs import simulate_custom_input

_this_directory = Path(__file__).parent
fmu_path = _this_directory/'../massSpringDamper3.fmu'

dump(fmu_path)

# m, k, b = 5, 0.5, 0.1
# dump(fmu_path)
# result = simulate_fmu(fmu_path)
# plot_result(result)


events=True
fmi_logging = True

result = simulate_fmu(
    filename=str(fmu_path),
    # validate=False,
    start_time=0,
    stop_time=12,
    # solver='CVode',
    step_size=1,
    # output_interval=2e-2,
    record_events=events,
    start_values={'b': 0.4, 'k':1, 'm': 1},
    # input=input,
    # output="Output",
    fmi_call_logger=lambda s: print('[FMI] ' + s) if fmi_logging else None)


plot_result(result=result,
    window_title="massSpringDamper3.fmu",
    events=events)
simulate_custom_input(fmu_path)