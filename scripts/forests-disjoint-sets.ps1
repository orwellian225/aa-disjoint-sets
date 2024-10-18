for ($trials = 1; $trials -le 5; $trials++) {
    for ($n = 10000; $n -le 100000; $n += 5000) {
        $data = $null
        Write-Host Trial $trials "|" n = ($n / 2)
        build\forest-experiment.exe ($n / 2) ($n / 2 - 1) | Tee-Object -Variable data
        $data | Out-File -FilePath "data\linked_data.csv" -Append -Encoding Utf8

        $data = $null
        Write-Host Trial $trials "|" n = $n
        build\forest-experiment.exe $n ($n - 1) | Tee-Object -Variable data
        $data | Out-File -FilePath "data\linked_data.csv" -Append -Encoding Utf8
    }
}