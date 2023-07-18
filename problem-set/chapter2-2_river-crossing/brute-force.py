import numpy as np

def time_accmulation(time:np.ndarray, status:np.ndarray, torch:bool):
    
    if status.all() == 1:
        return 0
    

    if torch == 0:
        for i in range(len(status)):
            single_test = 0
            if status[i] == 0:
                for j in range(i+1, len(status)):
                    if status[j] == 0:
                        
                        single_test = 1

                        status[i] = 1
                        status[j] = 1

                        return (time[i] + time[j]) + time_accmulation(time, status, 1)
                    
                if single_test == 0:
                    return time[i]
                
    if torch == 1:
        for i in range(len(status)):
            if status[i] == 1:
                
                status[i] = 0

                return time[i] + time_accmulation(time, status, 0)



if __name__ == '__main__':
    time = np.array([1,2,5,10])
    status = np.zeros(4, dtype=bool)
    torch = 0

    print(time_accmulation(time, status, torch))

    