""" This example demonstrates how to use the FMU.get*() and FMU.set*() functions
 to set custom input and control the simulation """

from fmpy import read_model_description, extract
from fmpy.fmi2 import FMU2Slave
from fmpy.util import plot_result, download_test_file
import numpy as np
import shutil


def simulate_custom_input(show_plot=True):

    # define the model name and simulation parameters
    # fmu_filename = 'CoupledClutches.fmu'
    fmu_filename = 'two_MSD_system.fmu'

    start_time = 0.0
    threshold = 10000
    stop_time = 300
    step_size = 6

    # download the FMU
    # download_test_file('2.0', 'CoSimulation', 'MapleSim', '2016.2', 'CoupledClutches', fmu_filename)

    # read the model description
    model_description = read_model_description(fmu_filename)

    # collect the value references
    vrs = {}
    for variable in model_description.modelVariables:
        vrs[variable.name] = variable.valueReference

    # extract the FMU
    unzipdir = extract(fmu_filename)

    fmu = FMU2Slave(guid=model_description.guid,
                    unzipDirectory=unzipdir,
                    modelIdentifier=model_description.coSimulation.modelIdentifier,
                    instanceName='instance1')

    # initialize
    fmu.instantiate()
    fmu.setupExperiment(startTime=start_time)
    fmu.enterInitializationMode()
    fmu.exitInitializationMode()

    time = start_time

    rows = []  # list to record the results

    # simulation loop
    while time < stop_time:

        # NOTE: the FMU.get*() and FMU.set*() functions take lists of
        # value references as arguments and return lists of values

        # set the input
        fmu.setReal([vrs['Input_Force'] ], [0.0 if time < 10 or time > 15 else 1.0])
        fmu.setReal([vrs['b1']], [1])
        fmu.setReal([vrs['k1']], [6])
        fmu.setReal([vrs['m1']], [50 if time < 75 else 10000])
        fmu.setReal([vrs['b2']], [6])
        fmu.setReal([vrs['k2']], [2])
        fmu.setReal([vrs['m2']], [50 if time < 75 else 10000])
        

        # perform one step
        fmu.doStep(currentCommunicationPoint=time, communicationStepSize=step_size)

        # advance the time
        time += step_size

        # get the values for 'inputs' and 'outputs[4]'
        inputs, outputs1, outputs2, outputs3, outputs4 = fmu.getReal([vrs['Input_Force'] , vrs['Position_1'], vrs['Position_2'], vrs['Velocity_1'], vrs['Velocity_2'] ])

        # append the results
        rows.append((time, inputs, outputs1, outputs2, outputs3, outputs4))

        # use the threshold to terminate the simulation
        if outputs1 > threshold:
            print("Threshold reached at t = %g s" % time)
            break        
        if outputs2 > threshold:
            print("Threshold reached at t = %g s" % time)
            break

    fmu.terminate()
    fmu.freeInstance()

    # clean up
    shutil.rmtree(unzipdir, ignore_errors=True)

    # convert the results to a structured NumPy array
    result = np.array(rows, dtype=np.dtype([('time', np.float64), ('input force', np.float64), ('x1', np.float64), ('x2', np.float64), ('v1', np.float64), ('v2', np.float64)]))

    # plot the results
    if show_plot:
        plot_result(result)

    return time


if __name__ == '__main__':

    simulate_custom_input()