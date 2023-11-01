import fmpy
from fmpy import plot_result
from fmpy.util import plot_result
from fmpy import *


m, k, b = 5, 0.5, 0.1
fmu_path = '../massSpringDamper3.fmu'
# dump(fmu_path)
# result = simulate_fmu(fmu_path)
# plot_result(result)



def simulate_custom_input(show_plot=True):
    global fmu_path

    # define the model name and simulation parameters
    start_time = 0.0
    threshold = 2.0
    stop_time = 2.0
    step_size = 1e-3

    # read the model description
    model_description = read_model_description(fmu_path)

    # collect the value references
    vrs = {}
    for variable in model_description.modelVariables:
        vrs[variable.name] = variable.valueReference

    # get the value references for the variables we want to get/set
    vr_inputs   = vrs['inputs']      # normalized force on the 3rd clutch
    vr_outputs4 = vrs['outputs[4]']  # angular velocity of the 4th inertia

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
        fmu.setReal([vr_inputs], [0.0 if time < 0.9 else 1.0])

        # perform one step
        fmu.doStep(currentCommunicationPoint=time, communicationStepSize=step_size)

        # advance the time
        time += step_size

        # get the values for 'inputs' and 'outputs[4]'
        inputs, outputs4 = fmu.getReal([vr_inputs, vr_outputs4])

        # append the results
        rows.append((time, inputs, outputs4))

        # use the threshold to terminate the simulation
        if outputs4 > threshold:
            print("Threshold reached at t = %g s" % time)
            break

    fmu.terminate()
    fmu.freeInstance()

    # clean up
    shutil.rmtree(unzipdir, ignore_errors=True)

    # convert the results to a structured NumPy array
    result = np.array(rows, dtype=np.dtype([('time', np.float64), ('inputs', np.float64), ('outputs[4]', np.float64)]))

    # plot the results
    if show_plot:
        plot_result(result)

    return time


# ------------------------------------------------------------------------------------------

simulate_custom_input()
