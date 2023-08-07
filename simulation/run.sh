SECONDS=0
echo 'Running No Control...'
../scripts/run_no_control.sh
echo 'Finished No Control!' '('$SECONDS' segundos)'

SECONDS=0
echo 'Running Quarantine (time)...'
../scripts/run_quarantine_time.sh
echo 'Finished Quarantine (time)!' '('$SECONDS' segundos)'

SECONDS=0
echo 'Running Quarantine (adherence)...'
../scripts/run_quarantine_adherence.sh
echo 'Finished Quarantine (adherence)!' '('$SECONDS' segundos)'

SECONDS=0
echo 'Running Random Vaccination (vaccination rate)...'
../scripts/run_random_vaccination_vrate.sh
echo 'Finished Random Vaccination (vaccination rate)!' '('$SECONDS' segundos)'

SECONDS=0
echo 'Running Random Vaccination (immunization rate)...'
../scripts/run_random_vaccination_irate.sh
echo 'Finished Random Vaccination (immunization rate)...!' '('$SECONDS' segundos)'

SECONDS=0
echo 'Running Degree Vaccination (vaccination rate)...'
../scripts/run_degree_vaccination_vrate.sh
echo 'Finished Degree Vaccination (vaccination rate)!' '('$SECONDS' segundos)'

SECONDS=0
echo 'Running Degree Vaccination (immunization rate)...'
../scripts/run_degree_vaccination_irate.sh
echo 'Finished Degree Vaccination (immunization rate)!' '('$SECONDS' segundos)'